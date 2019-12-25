# Similarities Instructions


## tl;dr
Implement a web app that enables a user to
- fill out a form, a la Google Forms, the results of which are saved to a comma-separated-value (CSV) file on the server, and
- view a table of all of the submissions received, a la Google Sheets.


## Specification
- Complete the implementation of `templates/form.html` in such a way that the form therein contains not only a button but also
    - one or more text fields of any type,
    - one or more checkboxes or two or more radio buttons,
    - one or more select menus, each with two or more options, and
    - zero or more other inputs of any type.
    Style that form using [Bootstrap](http://getbootstrap.com/docs/4.1/components/forms/) so that it looks nicer than it would with raw HTML alone.
    Add to that file some JavaScript code that prevents users from submitting the form if they have not provided values for one or more fields, alerting the user accordingly, as via `alert` or [Bootstrap](http://getbootstrap.com/docs/4.1/components/forms/).
- Complete the implementation of `post_form` in such a way that it
    - validates a form’s submission, alerting users with a `message` via `error.html` if they have not provided values for one or more fields, just in case your JavaScript code let something through (or was disabled),
    - writes the form’s values to a new row in `survey.csv` using `csv.writer` or `csv.DictWriter`, and
    - redirects the user to `/sheet`.
- Complete the implementation of `get_sheet` in such a way that it
    - reads past submissions from `survey.csv` using `csv.reader` or `csv.DictReader` and
    - displays those submissions in an HTML `table` via a new template.
    Style that table using [Bootstrap](http://getbootstrap.com/docs/4.1/components/forms/) so that it looks nicer than it would with raw HTML alone.
    Optionally enhance the table with JavaScript, as via [DataTables](https://datatables.net/examples/styling/bootstrap4).
Provided you meet these specifications, you’re welcome to alter the aesthetics of your app however you’d like, as via [Bootstrap](http://getbootstrap.com/docs/4.1/components/forms/) or your own CSS and HTML.


Full instructions available [here](https://docs.cs50.net/2019/x/psets/7/survey/survey.html)