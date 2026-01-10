export class ListNode {
  val: number;
  next: ListNode | null;

  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }

  static makeList(numbers: number[]) {
    if (numbers.length === 0) return null;

    const head = new ListNode(numbers[0]);
    let prev = head;

    for (let i = 1; i < numbers.length; ++i) {
      const number = numbers[i];
      const newNode = new ListNode(number);

      prev.next = newNode;
      prev = newNode;
    }

    prev.next = null;
    return head;
  }

  static makeCircularList = (data: [number[], number]) => {
    const numbers = data[0];
    const pos = data[1];
    if (numbers.length === 0) return null;

    const head = new ListNode(numbers[0]);
    let prev = head;
    let cycleStart: ListNode | null = pos === 0 ? head : null;

    for (let i = 1; i < numbers.length; ++i) {
      const newNode = new ListNode(numbers[i]);
      if (i === data[1]) cycleStart = newNode;

      prev.next = newNode;
      prev = newNode;
    }

    prev.next = cycleStart;
    return head;
  };

  static isSameList(head1: ListNode | null, head2: ListNode | null) {
    let node1 = head1;
    let node2 = head2;

    while (node1 !== null) {
      if (node2 === null) return false;
      if (node1.val !== node2.val) return false;

      node1 = node1.next;
      node2 = node2.next;
    }

    return node2 === null;
  }

  static detectCycle(head: ListNode | null) {
    let slow = head;
    let fast = head;
    let index = 0;

    while (slow !== null && fast !== null && fast.next !== null) {
      slow = slow.next;
      fast = fast.next.next;

      if (fast === slow) {
        slow = head;

        while (slow !== null && fast !== null) {
          if (slow === fast) return { cycle: slow, index };

          slow = slow.next;
          fast = fast.next;
          index++;
        }
      }
    }

    return { cycle: null, index: -1 };
  }

  static isSameCircularList(head1: ListNode | null, head2: ListNode | null) {
    const floyed1 = this.detectCycle(head1);
    const floyed2 = this.detectCycle(head2);

    if (floyed1.index !== floyed2.index) return false;

    let node1: ListNode | null = head1;
    let node2: ListNode | null = head2;

    // cycle 시작점까지 노드 비교
    for (let i = 0; i < floyed1.index; ++i) {
      if (node1 === null) return node2 === null;
      if (node2 === null) return node1 === null;
      if (node1.val !== node2.val) return false;

      node1 = node1.next;
      node2 = node2.next;
    }

    // 같은 cycle인지 비교
    while (true) {
      if (node1 === null) return node2 === null;
      if (node2 === null) return node1 === null;
      if (node1.val !== node2.val) return false;
      if (floyed1.cycle === node1) return floyed2.cycle === node2;
      if (floyed2.cycle === node2) return floyed1.cycle === node1;
      node1 = node1.next;
      node2 = node2.next;
    }
  }

  static splitList(node: ListNode | null, start: number, count: number) {
    let head: ListNode | null = node;

    for (let i = 0; i < start; ++i) {
      if (head === null) {
        throw new Error(`cannot split list started from ${start}`);
      }

      head = head.next;
    }

    let end: ListNode | null = head;

    for (let i = 0; i < count - 1; ++i) {
      if (end === null) {
        throw new Error(`cannot split list of node ${count}`);
      }

      end = end.next;
    }

    if (end !== null) end.next = null;
    return head;
  }
}
