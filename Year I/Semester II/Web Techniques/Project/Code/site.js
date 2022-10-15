if (process.env.NODE_ENV !== 'production') {
  require('dotenv').config();
}

const express = require('express');
const app = express();
const bcrypt = require('bcrypt');
const passport = require('passport');
const flash = require('express-flash');
const session = require('express-session');
const methodOverride = require('method-override');
const fs = require('fs');

const initializePassport = require('./config_file');
initializePassport(
  passport,
  email => users.find(user => user.email === email),
  id => users.find(user => user.id === id)
)

var users = [];

fs.readFile('views/accounts.json', 'utf-8', function(err, data) {
  if (err) {
    console.log("File read failed:", err);
    return;
  }
  
  try {
    users = JSON.parse(data);
    console.log("Successfully parsed data from Json file!");
  }
  catch(err) {
    console.log("Failed to parse data from Json file: ", err);
  }
});

app.set('view engine', 'ejs');
app.use(express.urlencoded({ extended: false }));
app.use(flash());
app.use(session({
  secret: process.env.SESSION_SECRET,
  resave: false,
  saveUninitialized: false
}))
app.use(passport.initialize());
app.use(passport.session());
app.use(methodOverride('_method'));
app.use(express.static('Home'));
app.use(express.static('Quiz'));
app.use(express.static('Articles'));
app.use(express.static('Video cards'));
app.use(express.static('Processors'));
app.use(express.static('Motherboards'));
app.use(express.static('Terminology'));
app.use(express.static('Account'));
app.use(express.static('Login'));
app.use(express.static('Register'));
app.use(express.static('404 Page'));

app.get('/', checkAuthenticated, (req, res) => {
  res.render('home.ejs', { name: req.user.name });
})

app.get('/login', checkNotAuthenticated, (req, res) => {
  res.render('login.ejs');
})

app.post('/login', checkNotAuthenticated, passport.authenticate('local', {
  successRedirect: '/',
  failureRedirect: '/login',
  failureFlash: true
}))

app.get('/register', checkNotAuthenticated, (req, res) => {
  res.render('register.ejs');
})

app.post('/register', checkNotAuthenticated, async (req, res) => {
  try {
    const hashedPassword = await bcrypt.hash(req.body.password, 10)
    users.push({
      id: Date.now().toString(),
      name: req.body.name,
      email: req.body.email,
      password: hashedPassword
    });

    fs.writeFile('views/accounts.json', JSON.stringify(users), err => {
      if (err) {
        console.log('Error writing to file: ', err);
      }
      else {
        console.log('Successfully wrote to file.');
      }
    });

    console.log(users);
    res.redirect('/login');
  } 
  catch {
    res.redirect('/register');
  }
});

app.delete('/logout', (req, res) => {
  req.logOut();
  res.redirect('/login');
})

function checkAuthenticated(req, res, next) {
  if (req.isAuthenticated()) {
    return next();
  }

  res.redirect('/login');
}

function checkNotAuthenticated(req, res, next) {
  if (req.isAuthenticated()) {
    return res.redirect('/');
  }

  next();
}

app.get('/home', function(req,res) {
  res.render('home.ejs');
});
app.get('/quiz', function(req,res) {
  res.render('quiz.ejs');
});
app.get('/articles', function(req,res) {
  res.render('articles.ejs');
});
app.get('/video_cards', function(req,res) {
  res.render('video_cards.ejs');
});
app.get('/processors', function(req,res) {
  res.render('processors.ejs');
});
app.get('/motherboards', function(req,res) {
  res.render('motherboards.ejs');
});
app.get('/terminology', function(req,res) {
  res.render('terminology.ejs');
});
app.get('/404', function(req,res) {
  res.render('404');
});
app.use(function(req, res) {
  res.status(404).redirect('/404');
});

app.listen(5000, function() {
  console.log("The server has started.");
});
