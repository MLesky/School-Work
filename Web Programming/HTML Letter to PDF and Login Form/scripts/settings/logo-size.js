const logoImage = document.querySelector('#label-for-logo');
const logoSizeSlider = document.querySelector('#logo-size-slider');
const logoSizeValue = document.querySelector("#logo-size-value");

let logoSize = 80;
logoSizeSlider.value = logoSize;
logoSizeValue.textContent = logoSize;

logoSizeSlider.addEventListener('change', (e) => {
    let size = e.target.value;
    logoImage.style.width = size + 'px';
    logoImage.style.height = size + 'px';
    logoSizeValue.textContent = size;
    logoSize = size;
})

export default logoSize;