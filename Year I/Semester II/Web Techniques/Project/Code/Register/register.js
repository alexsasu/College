window.onload = function() {
  var content = document.querySelector("#content");

  var register_form = document.querySelector(".register-form");
  var register_inputs = document.querySelectorAll(".register-input")
  var invalid_register_inputs = document.querySelectorAll(".invalid-register-input");
  for (i = 0; i < invalid_register_inputs.length; i++) {
    invalid_register_inputs[i].style.display = "none";
  }

  register_form.style.display = "block";

  document.body.addEventListener("click", function(e) {
    alert("You have clicked on a(n) "+e.target.nodeName+" element contained within a "+e.currentTarget.nodeName+" element. Fill in the fields in the login/register form in order to complete the login/registration.");
  });

  register_form.addEventListener("click", function(e) {
    e.stopPropagation();
  });

  register_inputs[0].addEventListener("click", function() {
    register_form.addEventListener("click", function() {
      if (register_inputs[0].value.length == 0) {
        invalid_register_inputs[0].style.display = "block";
        return;
      }
      else {
        invalid_register_inputs[0].style.display = "none";
      }
    });
  });

  register_inputs[1].addEventListener("click", function() {
    register_form.addEventListener("click", function() {
      if (register_inputs[1].value.length == 0) {
        invalid_register_inputs[1].style.display = "block";
        return;
      }
      else {
        invalid_register_inputs[1].style.display = "none";
      }
    });
  });

  register_inputs[2].addEventListener("click", function() {
    register_form.addEventListener("click", function() {
      if (register_inputs[2].value.length == 0) {
        invalid_register_inputs[2].style.display = "block";
        return;
      }
      else {
        invalid_register_inputs[2].style.display = "none";
      }
    });
  });

  document.querySelector(".butt2").addEventListener("click", function() {
    for (i = 0; i < 3; i++) {
      if (register_inputs[i].value.length == 0) {
        invalid_register_inputs[i].style.display = "block";
      }
    }
  });
}