module.exports = {
  entry: {
    app: './src/index.js',
  },
  output: {
    path: './public/',
    filename: '[name].js'
  },
  module: {
    loaders: [
      {
        test: /\.vue$/,
        loader: 'vue'
      },
      {
        test: /\.js$/,
        loader: 'babel',
        exclude: /node_modules/
      }
    ]
  },
  babel: {
    presets: ['es2015'],
    plugins: ['transform-runtime']
  },
  resolve: {
    alias: {
      vue: 'vue/dist/vue.js'
    }
  }
}
