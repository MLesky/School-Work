import './scripts/settings.js';
import './scripts/letter.js';

let show = true;
const toggleBtn = document.querySelector('#hider');
const settingsPannel = document.querySelector('main>div');
const header = document.querySelector('header');

toggleBtn.addEventListener('click', () => {
    if(show){
        settingsPannel.style.display = 'none';
        header.style.display = 'none';
        show = false;
    } else {
        settingsPannel.style.display = 'block';
        header.style.display = 'flex';
        show = true;
    }
})