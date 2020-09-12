var { Hero } = require('bindings')('addon');

var hero = new Hero("Iron Man", "wangcai");

var pet = hero.getPet();

console.log(`Hi, I'm ${hero.getName()}, I have a pet, its name is: ${pet.getName()}`);

console.log(hero);

console.log('Pet name: ', pet.getName()); // Pet name:  
