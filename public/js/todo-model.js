var app = app || {};
(function(){
  app.Todo = Backbone.Model.extend({
    defaults: {
      text: '',
      status: ''
    },
    changeStatus: function(){
      var newStatus = this.get("status") == 0 ? 1 : 0;
      this.save({ status: newStatus });
    }
  });
})();
