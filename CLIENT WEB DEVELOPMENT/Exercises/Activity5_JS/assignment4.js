quiz = {
    question : "What is HTML?",
    answers : [
        "High Translator Module Language", 
        "Hyper Text Markup Language",
        "Hyper Text Modelling Language",
        "Highest Text Markup Language"
    ],
    allocatedMarks: 5.0,
    correctAnswer: 2,
}

examQuestions = [
    {no: 1, question: "What is tag is used for bold", answers: ['b', 'br', 'bold', 'none'], allocatedMarks : 2, correctAnswer: 1},

    {no: 2, question: "What attribute is used to link a JavaScript file", answers: ['link', 'href', 'src', 'script'], allocatedMarks : 2, correctAnswer: 3},

    {no: 3, question: "What is style attribute is used for text color", answers: ['text-color', 'color', 'font-color', 'background-color'], allocatedMarks : 2, correctAnswer: 2},

    {no: 4, question: "How do you change the numbering of an ordered list", answers: ['using the style attribute', 'using the list-style-type attribute', 'none', 'using the type attribute'], allocatedMarks : 2, correctAnswer: 4},

    {no: 5, question: "What is tag is used for bold", answers: ['b', 'br', 'bold', 'none'], allocatedMarks : 2, correctAnswer: 1},

    {no: 6, question : "What is HTML?", answers : [
        "High Translator Module Language", 
        "Hyper Text Markup Language",
        "Hyper Text Modelling Language",
        "Highest Text Markup Language"
    ], allocatedMarks: 2, correctAnswer: 2,},

    {no: 7, question: "How many heading tags are there", answers: ['3', '6', 'just 1', '5'], allocatedMarks : 2, correctAnswer: 2},

    {no: 8, question: "How do you write single line comments in JavaScript", answers: ['after //', 'between /* and */', 'after #', 'Nothing'], allocatedMarks : 2, correctAnswer: 1},

    {no: 9, question: "What is tag is used for horizontal line", answers: ['h', 'line', 'horizon', 'hr'], allocatedMarks : 2, correctAnswer: 4},

    {no: 10, question: "Which is not a block element", answers: ['div', 'p', 'a', 'h1'], allocatedMarks : 2, correctAnswer: 3}
]

function showQuestions(){
    var box = document.querySelector(".questions")
    examQuestions.forEach(question => {
        box.innerHTML +=
        '<div class="question" id="'+ question.no + '">' + 
            '<h3>' + question.no + ": " + question.question + '</h3>' 
        for (var i = 0; i < 4; i++){
            box.innerHTML += '<div class="answer">' + 
            '<input type="radio" name="' + question.no + '" value="' + question.answers[i] +'"/>' +
            '<label>' + question.answers[i] + '</label>'
            '</div>'
        }
        '</div>'
    })
}

function mark(){
    var totalMark = 0, count = 0;
    var box = document.querySelector(".answers")
    examQuestions.forEach(question => {
        var options = document.getElementsByName(question.no)
        for (var i = 0; i < options.length; i++){
            if(options[i].checked){
                if(options[i].value == question.answers[question.correctAnswer - 1]){
                    totalMark += question.allocatedMarks
                    count++;
                    document.getElementById(question.no).style.color = 'green'
                    console.log("correct")
                }
                else {
                    document.getElementById(question.no).style.color = 'red'
                    console.log("wrong")
                }
            }
        }
    })
    document.querySelector(".result").innerHTML = 
    "You answered " + count + " questions correctly<br>" +
    "Final Mark = " + totalMark;
}