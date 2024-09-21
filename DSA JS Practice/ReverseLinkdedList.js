// Define a Node for the linked list
class ListNode {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

// Function to reverse the linked list
function reverseLinkedList(head) {
    let prev = null;
    let current = head;

    while (current !== null) {
        let nextNode = current.next; // Store the next node
        current.next = prev;         // Reverse the current node's pointer
        prev = current;              // Move prev and current one step forward
        current = nextNode;
    }

    return prev; // New head of the reversed list
}

// Helper function to print the linked list
function printList(head) {
    let current = head;
    while (current !== null) {
        process.stdout.write(current.value + " -> ");
        current = current.next;
    }
    console.log("null");
}

// Create the linked list: 1 -> 2 -> 3 -> 4 -> null
let head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
head.next.next.next = new ListNode(4);

console.log("Original Linked List:");
printList(head);

// Reverse the linked list
let reversedHead = reverseLinkedList(head);

console.log("Reversed Linked List:");
printList(reversedHead);

//   output must be
//   Original Linked List:
// 1 -> 2 -> 3 -> 4 -> null
// Reversed Linked List:
// 4 -> 3 -> 2 -> 1 -> null
