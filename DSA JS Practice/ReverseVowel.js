var reverseVowels = function(s) {
    let vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    let n = s.length;
    let i = 0;
    let j = n - 1;

    s = s.split('');

    while (i < j) {
        while (i < j && !vowels.has(s[i])) {
            i++;
        }
        while (i < j && !vowels.has(s[j])) {
            j--;
        }

        let temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

    return s.join('');
};