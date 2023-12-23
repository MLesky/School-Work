import { primaryColor, secondaryColor } from "./constants.js";

let alightment = 'left';

var alignmentBtns = document.querySelector('#alignment-buttons');
var leftBtn = alignmentBtns.querySelector('#left');
var centerBtn = alignmentBtns.querySelector('#center');
var rightBtn = alignmentBtns.querySelector('#right');
var letterHeader = document.querySelector('#letter-header');

leftBtn.addEventListener('click', () => {
    letterHeader.style.flexDirection = 'row'; 
    leftBtn.style.backgroundColor = secondaryColor;
    rightBtn.style.backgroundColor = primaryColor;
    centerBtn.style.backgroundColor = primaryColor;
    alightment = 'left';
})

rightBtn.addEventListener('click', () => {
    letterHeader.style.flexDirection = 'row-reverse'; 
    rightBtn.style.backgroundColor = secondaryColor;
    leftBtn.style.backgroundColor = primaryColor;
    centerBtn.style.backgroundColor = primaryColor;
    alightment = 'right';
})

centerBtn.addEventListener('click', () => {
    letterHeader.style.flexDirection = 'column'; 
    center.style.backgroundColor = secondaryColor;
    leftBtn.style.backgroundColor = primaryColor;
    rightBtn.style.backgroundColor = primaryColor;
    alightment = 'center';
})

export default alightment;