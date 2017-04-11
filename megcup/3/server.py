#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from mysecret import check_session_id, signtoken as do_signtoken
from simpleeval import simple_eval

from flask import Flask, request, make_response
import functools

app = Flask(__name__)

def require_login(func):
    @functools.wraps(func)
    def work():
        try:
            sid = request.cookies.get('sessionid')
            if not sid or not check_session_id(sid):
                return make_response('please login first', 401)
            return func()
        except:
            return 'error'
    return work

@app.route("/")
def hello():
    return "Hello World!"

@app.route("/echo")
@require_login
def echo():
    return make_response("""
        <h1>echo page</h1>
        <h2>request headers</h2><pre>{}</pre><h2>args</h2><pre>{}</pre>
    """.format(request.headers,
               '\n'.join('{}: {}'.format(k, v)
                         for k, v in request.args.items())))

@app.route("/eval")
@require_login
def eval_():
    expr = request.args['expr']
    result = simple_eval(expr)
    return make_response("""
        <h1>eval page</h1>
        <pre>{} = {}</pre>
    """.format(expr, result))

@app.route("/signtoken")
@require_login
def signtoken():
    token = request.args['token']
    signature = do_signtoken(token)
    return "token: {}<br />signature: {}".format(token, signature)

if __name__ == "__main__":
    app.run(debug=True, port=38701)
