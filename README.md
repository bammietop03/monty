<h1>Stacks, Queues - LIFO, FIFO</h1>
<img src="https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png" alt="stackqueue" width="100%" height="auto">
<h2>What is Stack in C?</h2>
<p>A stack in C is nothing but a linear data structure that follows the LIFO rule (Last In First Out). In a stack, both insertion and deletion take place from just one end, that is, from the top.</p>
<h2>More Info</h2>
<h3>What is a Queue in C?</h3>
<p>In contrast to a stack, a queue in C is nothing but a linear data structure that follows the FIFO rule (First In First Out). Insertion is done from the back (the rear end) and deletion is done from the front.</p>
<h3>The Monty language</h3>
<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>
<h5>Monty byte code files</h5>
<p>Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>
<code>julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$</code>
<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>
<code>julien@ubuntu:~/monty$ cat -e bytecodes/001.m
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
julien@ubuntu:~/monty$</code>
<h3>Compilation & Output</h3>
<ul>
<li>Your code will be compiled this way:</li>
<code>$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty</code>
