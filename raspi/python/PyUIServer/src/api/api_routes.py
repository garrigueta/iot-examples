from datetime import datetime
from flask import render_template, request, redirect, url_for, flash
from src.web import app, db, bcrypt
from src.web.forms import RegistrationForm, LoginForm
from src.web.models import User
from flask_login import login_user, current_user, logout_user

@app.route('/post', methods=['POST'])
def post():
    title = request.json['title']
    content = request.json['content']
    flash("OK")

@app.route('/get', methods=['GET'])
def get():
    title = request.json['title']
    content = request.json['content']
    flash("OK")
