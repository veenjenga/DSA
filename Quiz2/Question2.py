class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def findCycle(head):
    if not head or not head.next:
        return None

    slow = head.next
    fast = head.next.next

    while slow != fast:
        if not fast or not fast.next:
            return None
        slow = slow.next
        fast = fast.next.next

    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    return slow
