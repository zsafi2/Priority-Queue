Project Summary
Queues process elements in a first-in, first-out (FIFO) order, but FIFO is not the best order for all problems. For example, the problem of assisting patients in a hospital, in this case, you will want to service the patients who have the most critical injuries before others with less serious needs. In this project, you will write an abstraction class for a priority queue.


For the priority queue class that you will write, you can imagine using it for a patient queue at a hospital. As each new patient checks into the hospital, the staff assesses the patient’s injuries and gives them an integer priority rating. Smaller integers represent greater urgency, for example a patient of priority 1 is more urgent should receive care before a patient of priority 2. Once a doctor is ready to see a patient, the patient with the most urgent priority (i.e. with the lowest number rating) is seen first. However, you will be writing a more general purpose abstraction class. Therefore, it will work more generally for many types of priority queues.   


The basic design of a priority queue is that, regardless of the order in which you add/enqueue the elements, when you remove/dequeue them, the one with the lowest priority number comes out first, then second-lowest, and so on, with the highest-numbered (i.e. least urgent) item coming out last. In your implementation of the priority queue, if two or more elements in the queue have the same priority, you should break ties by choosing the element who was placed in the queue first. This means that if an element is placed in the queue at priority K and there are already other elements in the queue with priority K, your new element should be placed after them. For example, imagine you have a patient queue for a hospital and patients arrive in this order:
"Dolores" with priority 5
"Bernard" with priority 4
"Arnold" with priority 8
"William" with priority 5
"Teddy" with priority 5
"Ford" with priority 2

If you were to dequeue the patients to process them, they would come out in this order: Ford,
Bernard, Dolores, William, Teddy, Arnold.


A priority queue can internally store its elements in sorted or unsorted order; all that matters is that when the elements are dequeued, they come out in sorted order by priority. We will be specifying a very specific implementation in this project that you most adhere to. However, it is important to emphasize that abstraction classes can be implemented in lots of different ways.
Primary Project Topics
Trees
Linked Lists
Dynamic Memory
Test Frameworks

