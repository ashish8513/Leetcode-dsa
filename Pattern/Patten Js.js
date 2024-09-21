/**--------- 
 ****
 ****
 ****
 ****
------------*/

let n = 4
for (let row = 1; row <= n; row += 1) {
    let str = "";
    for (let row = 1; row <= n; row++) {
        str += "*"
    }
    console.log(str)
}

/** --------------
 * 
 **
 ***
 ****
 *****
 ----------------*/
let a = 5;
for (let row = 1; row <= a; row++) {
    let str = "*"
    console.log(str.repeat(row))
}

let b = 4;
for (let col = 1; col >= b; col++) {
    let str = "*";
    let space = ' ';
    console.log(space.repeat((b - 1)) + str.repeat(col))
}

/** --------------

           *
          **
         ***
        ****
       *****
      ******
     *******
    ********
   *********


   ----------------*/

let str5 = "";
let y = 10;
let x = 10;
for (let i = 1; i < y; i++) {
    for (let j = 1; j < x; j++) {
        if (i <= y / 2 && j >= (y / 2) - (i - 1) && j <= (y / 2) + (i - 1)) {
            str5 = str5.concat("*");
        } else if (i >= y / 2
            && j > ((y / 2) - i) * (-1)
            && j < (y - ((y / 2) - i) * (-1))) {
            str5 = str5.concat("*");
        }
        else {
            str5 = str5.concat(" ");
        }
    }
    str5 = str5.concat("\n");
}

console.log(str5)

/**------------------------


    *
   * *
  * * *
 * * * *
* * * * *

---------------------------*/

var h = '';
var f = 5;
var m = (f - 1);
for (i = 1; i <= n; i++) {
    h = h.trim();
    h = ' '.repeat(m) + h + (i > 1 ? ' ' : '') + '*';
    console.log(h);
    m--;
}