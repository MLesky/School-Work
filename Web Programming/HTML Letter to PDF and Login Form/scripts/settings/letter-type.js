import { primaryColor, secondaryColor } from "./constants.js";

let isFormalLetter = true;

const formalBtn = document.querySelector('#formal');
const informalBtn = document.querySelector('#informal');
const receiversField = document.querySelector('#reciever-address');
const subjectField = document.querySelector('#subject');

formalBtn.addEventListener('click', () => {
    receiversField.setAttribute('placeholder', 
    `To recipient's name\nRecipient's title\nReciepient's company\nReciepient's address`);
    receiversField.setAttribute('rows', '4');
    subjectField.style.display = 'block';
    formalBtn.style.backgroundColor = secondaryColor;
    informalBtn.style.backgroundColor = primaryColor;
    isFormalLetter = true;
    console.log('Formal', isFormalLetter);
});

informalBtn.addEventListener('click', () => {
    receiversField.setAttribute('placeholder', 
    `To recipient's name\nReciepient's address`);
    receiversField.setAttribute('rows', '2');
    subjectField.style.display = 'none';
    formalBtn.style.backgroundColor = primaryColor;
    informalBtn.style.backgroundColor = secondaryColor;
    isFormalLetter = false;
    console.log('Formal', isFormalLetter);
});


export default isFormalLetter;