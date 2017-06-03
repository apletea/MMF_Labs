var gulp        = require('gulp'), 
    browserSync = require('browser-sync');

gulp.task('browser-sync', function(){
	browserSync({
		port:1488,
		server: {
			baseDir: 'app'
		},
		notify: false
	});
});

gulp.task('watch', ['browser-sync'], function(){
	gulp.watch('app/**/*.html', browserSync.reload); 
	gulp.watch('app/js/**/*.js', browserSync.reload); 
});
gulp.task('default', ['watch','browser-sync']);
