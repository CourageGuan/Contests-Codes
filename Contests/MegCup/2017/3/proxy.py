#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#from mysecret import get_signed_session_id_raw
from flask import Flask, request, make_response
import requests

import base64

app = Flask(__name__)

UPSTREAM_URL = 'http://localhost:38701'

@app.route("/")
def hello():
    return "online proxy usage: /&lt;username&gt;/&lt;page&gt;"

@app.route("/<username>/<page>", methods=['GET', 'POST'])
def proxy(username, page):
    try:
        page = page.strip()
        assert set(page).issubset(set(
            chr(i) for i in range(ord('a'), ord('z') + 1)))
		#if page == 'signtoken':
			#return make_response('permission denied', 403)

		#sid = get_signed_session_id_raw(username)

		sid = '6a1a7cd402a9a0df55e3db28abf8c454'
        sid = base64.urlsafe_b64encode(sid).decode('utf-8')
        up_resp = requests.get(UPSTREAM_URL + '/' + page, params=request.args,
                               cookies={'sessionid': sid})

        # some debug pages may expose session id; strip them
        resp = up_resp.text.replace(sid, '<del>sessionid</del>')

        if request.form.get('debug'):
            resp += '<br /><hr>proxy debug<br />'
            resp += 'server response headers: <pre>{}</pre>'.format(
                up_resp.headers)

        return resp
    except:
        return 'error'


if __name__ == "__main__":
    app.run(debug=True, port=38700)
