function Person(name, value) {
    this.name = name;
    this.value = value;
}
Person.prototype.greet = function () {
    console.log(`hii My name is ${this.name} and the value is ${this.value}`);
}
const Ashish = new Person('Ashish Prabhakar', 20)

Ashish.greet();