const subject = document.querySelector('#subject');
const subjectSizeSlider = document.querySelector('#subject-size-slider');
const subjectSizeValue = document.querySelector("#subject-size-value");

let subjectSize = 24;

subjectSizeSlider.value = subjectSize;
subjectSizeValue.textContent = subjectSize;
console.log('Here 3', subject);
subjectSizeSlider.addEventListener('change', (e) => {
    let size = e.target.value;
    subject.style.fontSize = size + 'px';
    subjectSizeValue.textContent = size;
    subjectSize = size;
})

export default subjectSize;