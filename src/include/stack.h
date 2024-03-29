/*   Copyright 2019 Jônatas Batista
**
**   Licensed under the Apache License, Version 2.0 (the "License");
**   you may not use this file except in compliance with the License.
**   You may obtain a copy of the License at
**
**       http://www.apache.org/licenses/LICENSE-2.0
**
**   Unless required by applicable law or agreed to in writing, software
**   distributed under the License is distributed on an "AS IS" BASIS,
**   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**   See the License for the specific language governing permissions and
**   limitations under the License.
*/

#ifndef STACK_HEADER
#define STACK_HEADER

#include <stddef.h>

struct StackNode {
  void *data;
  struct StackNode *below;
};

typedef struct _Stack {
  struct StackNode *top;

  size_t size;
  void (*destructor)(void *data);
} Stack;

void stack_init(Stack *stack, void (*destroy)(void *data));
void stack_destroy(Stack *stack);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);

#endif
