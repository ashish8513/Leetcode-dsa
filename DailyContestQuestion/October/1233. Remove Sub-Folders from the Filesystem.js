// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

// If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

// The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

// For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
 

/**
 * @param {string[]} folder
 * @return {string[]}
 */
var removeSubfolders = function(folder) {
    let sortedFolder = folder.sort();
   let res = [sortedFolder[0]];
   let last = sortedFolder[0]
   for (let i = 1; i < sortedFolder.length; i++) {
       if (sortedFolder[i].startsWith(last + '/')) {
           continue;
       } else {
           res.push(last = sortedFolder[i]);
       }
   }
   return res
};