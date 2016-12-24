<template>
  <div class="todos">
    <ul>
      <li v-for="todo in todos">
        {{ todo.title }}
      </li>
    </ul>
    <div>
      <input type="text" placeholder="Add new Todo" v-model="newTodoTitle">
      <button @click="addTodo">Add</button>
    </div>
  </div>
</template>

<script>
  export default {
    data: function() {
      return {
        todos: [],
        newTodoTitle: ''
      }
    },
    methods: {
      addTodo: function() {
        if (!this.newTodoTitle) return;
        this.todos.push(new Module.Todo(this.newTodoTitle))
        this.newTodoTitle = ''
      }
    },
    created: function() {
      this.todos.push(new Module.Todo('Buy milk'))
    }
  }
</script>
