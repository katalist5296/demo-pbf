const button = document.getElementById('button');
button.addEventListener('click', function(e) {
	fetch('/fibonacci', {method: 'POST'})
		.then(function(response) {
			if(response.ok) return response.json();
			throw new Error('Request failed.');
		})
		.then(function(data) {
			document.getElementById('array').innerHTML = `${data}`;
		})
		.catch(function(error) {
			console.log(error);
		});
});

