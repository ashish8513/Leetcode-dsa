
function insertAM() {
    let data = [10, 3, 60, 46, 76, 54]
    let newEle = document.getElementById('newEl').vlaue;
    newEle=parseInt(newEle)
    let position = document.getElementById('position').value
    console.warn(data);

    for (let i = data.length - 1; i >= 0; i--) {
        if (i >= position) {
            data[i + 1] = data[i];
            if (i == position) {
                data[i] = newEle;
            }
        }
    }
    console.warn(data);
}