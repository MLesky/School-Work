import "./settings/body-size.js";
import "./settings/letter-head-color.js";
import "./settings/letter-head-size.js";
import "./settings/letter-type.js";
import "./settings/logo-size.js";
import "./settings/subject-size.js";
import "./settings/logo-alignment.js";

// var logoSize = document.querySelector('#logo-size');
// var letterHeadSize = document.querySelector('#letter-head-size');
// var letterHeadColor = document.querySelector('#letter-head-color');
// var subjectSize = document.querySelector('#subject-size');
// var bodySize = document.querySelector('#body-size');

adjustTextareaHeight();

function adjustTextareaHeight(textarea) {
  const textareas = document.querySelectorAll("textarea");
  textareas.forEach((textarea) => {
    textarea.addEventListener("input", () => {
      textarea.style.height = "auto"; // Reset the height to auto to recalculate the actual height
      textarea.style.height = textarea.scrollHeight + "px"; // Set the height to the scroll height
    });
    textarea.addEventListener("change", () => {
        textarea.style.height = "auto"; // Reset the height to auto to recalculate the actual height
        textarea.style.height = textarea.scrollHeight + "px"; // Set the height to the scroll height
      });
  });
}
