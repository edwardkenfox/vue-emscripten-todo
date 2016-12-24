<template>
  <div>
    <input type="checkbox" @change="toggle">
    <span>{{ todo.title }}</span>
    <span @click="remove(index)">✕</span>
  </div>
</template>

<script>
  export default {
    props: {
      todo: {
        type: Object,
        required: true,
      },
      remove: {
        type: Function,
        required: true,
      },
      index: {
        type: Number,
        required: true,
      }
    },

    methods: {
      toggle: function() {
        this.todo.toggle();
      }
    }
  }
</script>
