const addon = require('bindings')('fibonacci-addon')
const express = require('express');

const app = express();

app.use(express.static(__dirname + '/public'));

app.listen(8080, () => {
	console.log('listening on 8080');
});

app.get('/', (req, res) => {
	res.sendFile(__dirname + '/index.html');
});

app.post('/fibonacci', (req, res) => {
	res.send(addon.get(9));
});

