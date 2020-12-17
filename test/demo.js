const addon = require('bindings')('fibonacci-addon')

console.log(addon.get(9));
