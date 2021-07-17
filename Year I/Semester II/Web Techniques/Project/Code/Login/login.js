window.onload = function() {
  var content = document.querySelector("#content");

  var login_form = document.querySelector(".login-form");
  var login_inputs = document.querySelectorAll(".login-input")
  var invalid_login_inputs = document.querySelectorAll(".invalid-login-input");
  for (i = 0; i < invalid_login_inputs.length; i++) {
    invalid_login_inputs[i].style.display = "none";
  }

  login_form.style.display = "block";

  document.body.addEventListener("click", function(e) {
    alert("You have clicked on a(n) "+e.target.nodeName+" element contained within a "+e.currentTarget.nodeName+" element. Fill in the fields in the login/register form in order to complete the login/registration.");
  });

  document.querySelector("#no-account").addEventListener("click", function() {
    for (i = 0; i < invalid_login_inputs.length; i++) {
      invalid_login_inputs[i].style.visibility = "hidden";
    }

    login_form.style.display = "none";
    register_form.style.display = "block";
  });

  login_form.addEventListener("click", function(e) {
    e.stopPropagation();
  });

  login_inputs[0].addEventListener("click", function() {
    login_form.addEventListener("click", function() {
      if (login_inputs[0].value.length == 0) {
        invalid_login_inputs[0].style.display = "block";
        return;
      }
      else {
        invalid_login_inputs[0].style.display = "none";
      }
    });
  });

  login_inputs[1].addEventListener("click", function() {
    login_form.addEventListener("click", function() {
      if (login_inputs[1].value.length == 0) {
        invalid_login_inputs[1].style.display = "block";
        return;
      }
      else {
        invalid_login_inputs[1].style.display = "none";
      }
    });
  });

  document.querySelector("#butt1").addEventListener("click", function() {
    for (i = 0; i < 2; i++) {
      if (login_inputs[i].value.length == 0) {
        invalid_login_inputs[i].style.display = "block";
      }
    }
  });
}