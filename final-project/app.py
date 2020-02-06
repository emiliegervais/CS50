import os

from flask import Flask, redirect, render_template

from helpers import get_data, random_class, random_code

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded on change
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Get data using helper function get_data()
data = get_data('data.json')

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route('/')
def index():
    """ Show status-code per responses class """

    return render_template('index.html', data = data)


@app.route('/status', strict_slashes=False)
def status():
    """ Redirect to a random status-code page """

    # Get random status-code 
    code = random_code(random_class(data), data)

    # Redirect to random status-code page
    return redirect('/status/{}'.format(code))


@app.route('/status/<code>', strict_slashes=False)
def status_code(code):
    """ Show status-code information """

    # Set code number as index
    i = code

    # Loop through status code classes
    for k, v in data.items():
        # Check if current code is part of this class status codes
        if i in v['status']:
            code = v['status'][i]
            code.update({ 'code': i })
            code.update({ 'classname': k})
            code.update({ 'class_definition': v['definition']})
    
            return render_template('status-code.html', code = code)

    # If code is Not Found
    return render_template('apology.html')
    

# Get setup so that if we call the app directly (and it isn't being imported elsewhere)
# it will then run the app with the debug mode as True
# More info - https://docs.python.org/3/library/__main__.html
if __name__ == '__main__':
    app.run()