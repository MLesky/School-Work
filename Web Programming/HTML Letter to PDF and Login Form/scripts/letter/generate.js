import 'https://cdnjs.cloudflare.com/ajax/libs/jspdf/2.5.1/jspdf.umd.min.js';

import logoSize from '../settings/logo-size.js';
import alightment from '../settings/logo-alignment.js';

const generateButtons = document.querySelectorAll('.generate-btn');
const sideButtons = document.querySelectorAll('.side-btn');
const printButton = document.querySelector('#print-btn');

const logoElem = document.querySelector('#logo-picker');
const logoPicker = document.getElementById('logo-picker');
const letterHeadElem = document.querySelector('#letter-head');
const senderElem = document.querySelector('#sender-address');
const dateElem = document.querySelector('#date');
const recieverElem = document.querySelector('#reciever-address');
const subjectElem = document.querySelector('#subject');
const greetingsElem = document.querySelector('#greeting');
const bodyElem = document.querySelector('#body-paragraph');
const signatureElem = document.querySelector('#salutation');
const nameElem = document.querySelector('#signature');

console.log('Side', sideButtons);
printButton.addEventListener('click', () => {
    sideButtons.forEach(button => {
        button.style.right = '-300px';
    });
    print();
    sideButtons.forEach(button => {
        button.style.right = '0';
    });
});

generateButtons.forEach(button => {
    button.addEventListener('click', generatePDF2)
})

function generatePDF1() {
    console.log('Generating....');
    var letterForm = document.querySelector('#letter-form');
    html2pdf(letterForm);
}

function generatePDF2() {
    const doc = new jspdf.jsPDF();
    if(alightment === 'left'){
        doc.addImage(logoPicker.value, 'JPEG', 10, 10, logoSize, logoSize);
        doc.text(letterHeadElem.value, logoSize + 5, 10);
        console.log('Image: ', logoPicker.value);
    }
    doc.save('letter.pdf');
}