# HTTP Status Code Cheatsheet

**Environment:** Python, Flask, JavaScript, Jinja2, HTML5, CSS, Git, Heroku

## About 
For my CS50 Final Project, I wanted to make something that would end up being useful for me and other developers. I ended up developing a simple, but aesthetically pleasant HTTP Status Code Cheatsheet. Animal pictures corresponding to the different status-codes were added for their cuteness.

### Routes
`./`
The index lets you browse summary cards for all current official and non-customized status-codes classified under its proper response class. This page aims to be useful when needing to find quick information about a specific status-code when building an API per example.
 
`./status`
This route redirects the user to a random status page. It is used by the gigantic button fixed on the top of the page, kind of acting like a full width navigation bar. Clicking on it brings us to a random status-code, the next route:

`./status/<code>`
Here, we gain access to a slightly more condensed status-code card. The goal of this card is to give access to all of the information related to a specific status-code in one place easily accessible under a specific URL. The URL structure is made logic and simple because we want to be able to browse the cards using the browser's location bar only.

### Architecture 
Since it is a small application and it won't ever scale, the architecture is _basic_:
```
./
  static/
    css/
    fonts/
    images/
    favicon.gif
  templates/
    components/
    partials/
  app.py
  helpers.py
  data.json
  Procfile
  README.md
  requirements.txt
```

#### Resources
Status-code information was gathered from [Hypertext Transfer Protocol (HTTP) Status Code Registry](https://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml) and [Mozilla Developer Network](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status). 

Images are from [Museum of Internet](https://Museumofinter.net).