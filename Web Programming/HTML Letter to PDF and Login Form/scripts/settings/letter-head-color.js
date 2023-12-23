let letterHeadColor = '#000000';

const letterHeadColorPicker = document.querySelector('#letter-head-color-picker');
const letterHead = document.querySelector('#letter-head');

letterHeadColorPicker.addEventListener('change', (e) => {
    let color = e.target.value;
    letterHead.style.color = color;
    letterHeadColor = color;
})