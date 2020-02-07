# HTTP Status Code Cheatsheet

**Environment:** Python, Flask, JavaScript, Jinja2, HTML5, CSS

## About 
For my CS50 Final Project, I wanted to build something that could be  useful for me & other developers. I ended up developing a simple, but aesthetically pleasant HTTP Status Code Cheatsheet web application.  Animal pictures corresponding to the different status codes were added for their cuteness.

To run it: `python app.py`

### Routes
`./`
The index route lets us browse summary cards for all current official and non-customized status codes. Each status code is classified under its response class. The index aims to be useful when needing to find quick information about a specific status code, per example when building an API.
 
`./status`
The status route redirects us to a random status page: it is used by the button fixed at the top of the page to act as a full width navigation bar. 

`./status/<code>`
The status code route lets us access a condensed status code card displaying all the information related to that specific status code. The aim here is to provide us access to that information easily and quickly. The URL structure is logical, allowing us to browse the cards using the browser's location bar only.

### Resources
Status-code information was gathered from [Hypertext Transfer Protocol (HTTP) Status Code Registry](https://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml) and [Mozilla Developer Network](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status). 

Images are from [Museum of Internet](https://Museumofinter.net).