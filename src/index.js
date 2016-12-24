import Vue from 'vue'
import App from './components/App.vue'

window.vm = new Vue({
  components: {
    App
  }
}).$mount('#app')
