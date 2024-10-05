function name_shorter(name, maxLength) {
    if (name.length > maxLength) {
        return name.substring(0, maxLength) + '...';
    }
    return name
}
let newName = name_shorter("Ashish Prabhakar", 8)
console.log(newName)