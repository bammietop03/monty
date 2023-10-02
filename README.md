<h1>Stacks, Queues - LIFO, FIFO</h1>
<img src="https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png" alt="stackqueue" width="100%" height="auto">
<h2>What is Stack in C?</h2>
<p>A stack in C is nothing but a linear data structure that follows the LIFO rule (Last In First Out). In a stack, both insertion and deletion take place from just one end, that is, from the top.</p>
<h3>What is a Queue in C?</h3>
<p>In contrast to a stack, a queue in C is nothing but a linear data structure that follows the FIFO rule (First In First Out). Insertion is done from the back (the rear end) and deletion is done from the front.</p>
<h2>More Info</h2>
<h3>The Monty language</h3>
<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>
<h4>Monty byte code files</h4>
<p>Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>
<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$</code></pre>
<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>
<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$</code></pre>
<h3>Compilation & Output</h3>
<code>$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty</code>
<h3>Supported Opcodes</h3>
<p>The following opcodes are supported by the interpreter:</p>
<ul>
<li><code>push:</code>Pushes an integer onto the stack</li>
<li><code>pop:</code>Removes the top element of the stack</li>
<li><code>swap:</code>Swaps the top two elements of the stack</li>
<li><code>add:</code>Adds the top two elements of the stack.</li>
<li><code>sub:</code>Subtracts the top element of the stack from the second top element.</li>
<li><code>div:</code>Divides the second top element of the stack by the top element.</li>
<li><code>mul:</code>Multiplies the second top element of the stack with the top element.</li>
<li><code>mod:</code>Computes the modulus of the second top element of the stack with the top element of the stack.</li>
<li><code>pall:</code>Prints all the values on the stack.</li>
<li><code>pint:</code>Prints the value at the top of the stack.</li>
<li><code>pchar:</code>Prints the character at the top of the stack.</li>
<li><code>pstr:</code>Prints the string starting at the top of the stack.</li>
<li><code>nop:</code>Does nothing.</li>
<li><code>comments:</code>The capability of commenting.</li>
<li><code>rotl:</code>Moves element at the top to the bottom of the stack.</li>
<li><code>rotr:</code>The bottom of the stack becomes the top.</li>
<li><code>queue, stack:</code>Toggles the doubly link list implementation style</li>
<h3>Example</h3>
<pre>
<code>
julien@ubuntu:~/monty$ cat bytecodes/35.m
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
julien@ubuntu:~/monty$ ./monty bytecodes/35.m
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
julien@ubuntu:~/monty$
</code>
</pre>
</ul>
<h2>Authors</h2>
<p>This program was written by:</p>
<p>Nkechi Christabel Udenkwor <udenkwornkechi@gmail.com></p>
<p>Bamiwo Adebayo <Bammietop@gmail.com></p>
