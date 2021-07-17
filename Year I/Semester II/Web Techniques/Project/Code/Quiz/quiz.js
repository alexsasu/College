window.onload = function()
{
  var time = document.querySelector("#time");
  time.style.display = "none";
  var desc = document.querySelector("#description");
  var questions = document.querySelectorAll(".question");
  var actual_question = document.querySelectorAll(".actual-question");
  for (i = 0; i < questions.length; i++) {
    questions[i].style.display = "none";
  }

  var start_button = document.createElement("button");
  document.querySelector("#content").appendChild(start_button);
  start_button.innerHTML = "Start";
  start_button.classList.add("start");

  document.querySelector("footer").classList.add("footer-aux");

  start_button.onclick = function() {
    desc.style.display = "none";
    start_button.remove();
    time.style.display = "block";
    for (i = 0; i < 15; i++) {
      questions[i].style.display = "block";
    }
    var finish_button = document.createElement("button");
    document.querySelector("#content").appendChild(finish_button);
    finish_button.innerHTML = "Finish quiz";
    finish_button.classList.add("start");
    finish_button.style.paddingTop = parseInt(window.getComputedStyle(finish_button).padding)+3+'px';
    finish_button.style.paddingBottom = parseInt(window.getComputedStyle(finish_button).padding)+3+'px';
    finish_button.style.marginTop = parseInt(window.getComputedStyle(finish_button).padding)+15+'px';
    finish_button.style.marginBottom = parseInt(window.getComputedStyle(finish_button).padding)+5+'px';

    document.querySelector("footer").classList.remove("footer-aux");

    let array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14];
    array = array.sort(() => Math.random() - 0.5);
    var node;
    var nodesArray = [];
    for (i = 0; i < 15; i++) {
      node = questions[i].cloneNode(true);
      nodesArray.push(node);
    }
    for (i = 0; i < 15; i++) {
      questions[i].innerHTML = nodesArray[array[i]].innerHTML;
      actual_question[i].innerHTML = (i+1)+". "+actual_question[i].innerHTML;
    }

    var t = setTimeout(function() {
      alert("Time is up!");

      var buttons = document.querySelectorAll("input");
      for (i = 0; i < buttons.length; i++) {
        buttons[i].disabled = true;
      }

      var nr = 0;
      for (i = 0; i < buttons.length; i++) {
        if (buttons[i].checked == true && buttons[i].value == "corect") {
          nr++;
        }
      }

      finish_button.innerHTML = (JSON.stringify(nr)).concat(" correct answer(s)!");
      var corranss = document.querySelectorAll(".corrans");
      for (i = 0; i < 15; i++) {
        corranss[i].classList.add("highlight");
      }
    }, 482000)

    var fiveMinutes = 60*8;
    display = document.querySelector('#time');
    var timer = fiveMinutes, minutes, seconds;
    var startTimer = setInterval(function () {
      minutes = parseInt(timer / 60, 10);
      seconds = parseInt(timer % 60, 10);

      minutes = minutes < 10 ? minutes : minutes;
      seconds = seconds < 10 ? "0" + seconds : seconds;

      display.textContent = minutes + ":" + seconds;

      if (timer-- < 1) {
        clearInterval(startTimer);
        return;
      }

      finish_button.addEventListener("click", function() {
        clearInterval(startTimer);
      });
    }, 1000);

    finish_button.addEventListener("click", function() {
      clearTimeout(t);

      var buttons = document.querySelectorAll("input");
      for (i = 0; i < buttons.length; i++) {
        buttons[i].disabled = true;
      }

      var nr = 0;
      for (i = 0; i < buttons.length; i++) {
        if (buttons[i].checked == true && buttons[i].value == "correct") {
          nr++;
        }
      }
      
      finish_button.innerHTML = (JSON.stringify(nr)).concat(" correct answer(s)!");

      var corranss = document.querySelectorAll(".corrans");
      for (i = 0; i < 15; i++) {
        corranss[i].classList.add("highlight");
      }
    });
  }
}