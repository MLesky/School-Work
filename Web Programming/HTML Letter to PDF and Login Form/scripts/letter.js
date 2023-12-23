import './letter/image.js';
import './letter/generate.js';
const letterHead = 'Letter In HTML FORMS To PDF';
const sendersDetails = "Mbah Lesky T.\nmbahlesky2@gmail.com";
const date = Date.now().toString();
const recieversDetails = "Kelly Melly S.\n22nd Street, Texas";
const subject = "A Letter To Apply For A Job";
const body = "Hey [Friend's Name]! How's it going, buddy? It feels like ages since we last caught up, and I've been missing our crazy adventures together. I hope this letter finds you in high spirits and having a blast. First things first, let me fill you in on what's been happening in my life lately. Remember that job I was applying for? Well, I got it! I'm super excited about it. The workplace is pretty cool, and my colleagues are a fun bunch. The learning curve is steep, but I'm up for the challenge. Wish me luck! Now, let's talk about you. How are things on your end? Have you finally conquered that video game you were obsessed with? I'm curious to know if you managed to defeat that insanely difficult boss level. \n\nRemember, I'm always ready for a rematch if you need a co-op partner! Oh, and speaking of games, have you heard about the new console that just hit the market? It's got all the bells and whistles you can imagine. I've been eyeing it, but my bank account is giving me the evil eye. Let me know if you decide to get it, though. I might have to live vicariously through your gaming adventures for a while. On a more serious note, how's everything else going? Are you still pursuing that passion project you mentioned? I believe in you, my friend. Don't let anyone or anything discourage you from chasing your dreams. I'm here to cheer you on every step of the way. By the way, did you hear about that crazy hiking trip I took last month? I ventured into the mountains with a group of daredevil adventurers. It was breathtaking! Literally, because the altitude nearly knocked the wind out of me. But the views were absolutely worth it. I'll definitely share the pictures with you when we meet up. Speaking of meeting up, we really need to plan a hangout soon. It's been way too long since we laughed until our stomachs hurt and shared embarrassing stories. \n\nLet's find a day when we're both free and do something epic. Maybe we can go on a road trip or try out that new restaurant downtown. I'm open to suggestions! Alright, my friend, I'll wrap this letter up now. But before I go, I want you to know that you're an amazing person, and our friendship means the world to me. Whenever you need someone to talk to, remember that I'm just a call or text away. Take care of yourself, keep rocking, and let's make some unforgettable memories soon! Until we meet again";
const signature = 'Yours Truly';
const name = "Lespa";

const letterHeadElem = document.querySelector('#letter-head');
const senderElem = document.querySelector('#sender-address');
const dateElem = document.querySelector('#date');
const recieverElem = document.querySelector('#reciever-address');
const subjectElem = document.querySelector('#subject');
const greetingsElem = document.querySelector('#greeting');
const bodyElem = document.querySelector('#body-paragraph');
const signatureElem = document.querySelector('#salutation');
const nameElem = document.querySelector('#signature');

const fillBtn = document.querySelector('#fill-btn');

fillBtn.addEventListener('click', () => {
    letterHeadElem.value = letterHead;
    senderElem.value = sendersDetails;
    dateElem.value = date;
    recieverElem.value = recieversDetails;
    greetingsElem.value = 'Dr Friend,';
    subjectElem.value = subject;
    bodyElem.value = body;
    signatureElem.value = signature;
    nameElem.value = name;
})