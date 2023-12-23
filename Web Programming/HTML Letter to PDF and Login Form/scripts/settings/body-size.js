const body = document.querySelectorAll('.body *');
const bodySizeSlider = document.querySelector('#body-size-slider');
const bodySizeValue = document.querySelector("#body-size-value");

let bodySize = 16;

bodySizeSlider.value = bodySize;
bodySizeValue.textContent = bodySize;
bodySizeSlider.addEventListener('change', (e) => {
    let size = e.target.value;
    console.log('jlkjds');
    body.forEach(element => {
        element.style.fontSize = size + 'px';
    });
    bodySizeValue.textContent = size;
    bodySize = size;
})

export default bodySize;