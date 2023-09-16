from datetime import datetime
from flask import render_template, request, redirect, url_for, flash
from src.web import app, db, bcrypt
from src.web.forms import RegistrationForm, LoginForm
from src.web.models import User
from flask_login import login_user, current_user, logout_user

feedbacks = []


def store_feedback(url):
    feedbacks.append(dict(
        url=url,
        user='Loonycorn',
        date=datetime.utcnow()
    ))


def new_feedbacks(num):
    return sorted(feedbacks, key=lambda bm: bm['date'], reverse=True)[:num]


# view function

@app.route('/')
@app.route('/index')
def index():
    return render_template('index.html', new_feedbacks=new_feedbacks(3))


@app.route('/add', methods=['GET', 'POST'])
def add():
    if request.method == "POST":
        url = request.form['url']
        store_feedback(url)
        flash("Your Feedback : " + url)
        return redirect(url_for('index'))
    return render_template("add.html")

@app.route('/post', methods=['POST'])
def post():
    title = request.json['title']
    content = request.json['content']
    db.



@app.route("/register", methods=['GET', 'POST'])
def register():
    if current_user.is_authenticated:
        return redirect(url_for('index'))
    form = RegistrationForm()
    if form.validate_on_submit():
        hashed_password = bcrypt.generate_password_hash(form.password.data)
        user = User(username=form.username.data, email=form.email.data, password=hashed_password)
        db.session.add(user)
        db.session.commit()
        flash('Account created !')
        return redirect(url_for('login'))

    if form.errors:
        flash('Validation Errors: ' + str(form.errors))
        app.logger.error('ValidationError:\n' + str(form.errors))

    return render_template('register.html', title='Register', form=form)


@app.route("/login", methods=['GET', 'POST'])
def login():
    if current_user.is_authenticated:
        return redirect(url_for('index'))
    form = LoginForm()
    if form.validate_on_submit():
        user = User.query.filter_by(email=form.email.data).first()
        if user and bcrypt.check_password_hash(user.password, form.password.data):
            login_user(user)
            return redirect(url_for('index'))
        else:
            flash('Login Unsuccessful')
    return render_template('login.html', title='Login', form=form)


@app.route("/logout")
def logout():
    logout_user()
    return redirect(url_for('index'))


@app.route("/sale")
def sale():
    return render_template('sale.html')


@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404
