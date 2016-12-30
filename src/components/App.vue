<template>
  <div>
    <ul>
      <li v-for="(todo, index) in todos">
        <todo :todo="todo" :remove="removeTodo" :index="index"></todo>
      </li>
    </ul>
    <input type="text" placeholder="Add new Todo" v-model="title">
    <button @click="addTodo">Add</button>
  </div>
</template>

<script>
import Todo from './Todo.vue'

export default {
  components: {
    Todo
  },

  data: function() {
    return {
      todos: [],
      title: ''
    }
  },

  methods: {
    addTodo: function() {
      if (!this.title) return;
      this.todos.push(new Module.Todo(this.title))
      this.title = ''
    },

    removeTodo: function(index) {
      this.todos[index].delete();
      this.todos.splice(index, 1);
    }
  },

  created: function() {
    this.todos.push(new Module.Todo('Buy milk'))
  }
}
</script>
