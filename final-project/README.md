# HTTP Status Code Cheatsheet
_A web application built using Python, the framework Flask and the template engine Jinja2._
_The codebase is hosted on Github and the app is deployed on Heroku using the Python buildpack._

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
Since it is a small application, the architecture is basic:
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
If it ever scales, it would require some refactoring. 

#### Resources
Status-code information was gathered from [Hypertext Transfer Protocol (HTTP) Status Code Registry](https://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml) and [MDN](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status).

Images are from [Museum of Internet](https://Museumofinter.net)

---
Source for this project: [https://github.com/hexangel616/http-status-code-cheatsheet](https://github.com/hexangel616/http-status-code-cheatsheet)

Project URL: [https://status-code-cheatsheet.herokuapp.com](https://status-code-cheatsheet.herokuapp.com)
