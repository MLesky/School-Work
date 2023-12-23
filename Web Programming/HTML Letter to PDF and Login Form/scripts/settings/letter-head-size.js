const letterHead = document.querySelector('#letter-head');
const letterHeadSizeSlider = document.querySelector('#letter-head-size-slider');
const letterHeadSizeValue = document.querySelector("#letter-head-size-value");

let letterHeadSize = 40;
letterHeadSizeSlider.value = letterHeadSize;
letterHeadSizeValue.textContent = letterHeadSize;

letterHeadSizeSlider.addEventListener('change', (e) => {
    let size = e.target.value;
    letterHead.style.fontSize = size + 'px';
    letterHeadSizeValue.textContent = size;
    letterHeadSize = size;
})

export default letterHeadSize;