format:
	clang-format -i -style=file **/*.cpp **/*.h

cleanup:
	rm -f **/*.o **/*.s **/out
	clang-format -i -style=file **/*.cpp

push:
	clang-format -i -style=file **/*.cpp
	git add .
	git commit -m "$m"
	git push origin master
