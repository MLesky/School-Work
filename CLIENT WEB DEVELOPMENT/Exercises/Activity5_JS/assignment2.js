function create(){
    var blog = {
        no : 1,
        title : "Client Web Development",
        body : "Lorem ipsum dolor sit amet consectetur adipisicing elit. Odio, aliquid amet facere architecto ex debitis ipsum, obcaecati tenetur consectetur eligendi accusamus ullam totam animi dolorum quae eaque. Quibusdam pariatur vel, odit repudiandae accusamus nisi laborum, magnam explicabo recusandae aliquid incidunt sit aliquam! Obcaecati, neque sed ipsa animi iusto sunt alias omnis totam velit culpa tenetur odio enim nam rerum est maiores cupiditate illum, vitae minima voluptas facere corporis asperiores? Est, harum. Cumque alias et, possimus, nisi deserunt consequuntur ratione deleniti necessitatibus quos blanditiis, magnam laudantium maxime maiores repellat inventore quas.",
        author: "Mbah Lesky",
        dateCreated: new Date("2023-01-19T12:04:00"),
        comments: [
            {name: 'Lespa', comment: 'this is good'},
            {name: 'Mbah', comment: 'this is nice'},
        ],
        tags: ["Web", "Client-side", "Front-End", "Software engineering"],
        addComment: function() {
            var name = prompt("Enter name")
            var comment = prompt("Enter comment")
            this.comments.push({name: name, comment : comment})
        }
    }
   
    document.querySelector(".blog-posts").innerHTML = '<div class="blog">' +
        '<h2>Title: '+ blog.title + '</h2>' +
        '<h5>Author: ' + blog.author + '</h5>' +
        '<p>' + blog.body + '</p>' +
        '<h5 class"date-created">Date created: ' + blog.dateCreated + '</h5>'
        '</div>'
}