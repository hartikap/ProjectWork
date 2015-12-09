var main_module = angular.module('main_module', ['ngRoute']);

main_module.config(function($routeProvider) {
    
    $routeProvider
        .when('/', {
        templateUrl: 'partial_login.html'
        controller: 'loginController'
    })
    
    
});