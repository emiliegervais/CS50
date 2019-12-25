import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():

    # Get content from form
    name = request.form.get("name")
    email = request.form.get("email")
    number = request.form.get("number")
    catlover = request.form.get("catlover")
    behaviors = request.form.get("behaviors")
    soylent = request.form.get("soylent")
    comments = request.form.get("comments")

    # If required fields are there:
    if name and email and number and soylent:
        with open("survey.csv", "a", newline="") as file:
            fieldnames = ["name", "email", "number", "catlover", "behaviors", "soylent", "comments"]
            writer = csv.DictWriter(file, fieldnames=fieldnames)
            # Write content to survey.csv
            writer.writerow({
                "name": name,
                "email": email,
                "number": number,
                "catlover": catlover,
                "behaviors": behaviors,
                "soylent": soylent,
                "comments": comments
            })
        # Redirect to /sheet
        return redirect("/sheet")
    # If required fields are not there, render error template
    else:
        return render_template("error.html", message="Please fill out the form before submitting.")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    # Open survey.csv
    with open("survey.csv") as file:
        reader = csv.DictReader(file)
        # Create a list from file content
        data = list(reader)
        # If data, render sheet template
        if data:
            return render_template("sheet.html", data=data)
        # If not data, render error template
        else:
            return render_template("error.html", message="No data was found. Please try again later.")