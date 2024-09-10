
CC               := clang
TEST_LINK_FLAGS  := -lcriterion
CFLAGS           := $(CFLAGS) -std=c11
# CFLAGS      := $(CFLAGS) -Werror -Wall -Wextra -std=c11  # conversion error in current criterion

OBJECTS := arrays.o
TESTS := $(addsuffix _test,$(patsubst %.o,%,$(OBJECTS)))

all: $(TESTS)

$(OBJECTS): %.o: %.c %.h
	$(CC) -c -o $@ $(CFLAGS) $<

$(TESTS): %: %.c $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $< $(subst _test,,$@).o $(TEST_LINK_FLAGS)

.PHONY: test
test: $(TESTS)
	$(info running the following tests: $^)
	$(foreach TEST,$(TESTS),$(shell ./$(TEST)))

.PHONY: average
average: $(TESTS)
	./arrays_test --filter arrays/$@

.PHONY: initialize_range
initialize_range: $(TESTS)
	./arrays_test --filter arrays/$@

.PHONY: minimum
minimum: $(TESTS)
	./arrays_test --filter arrays/$@*

.PHONY: maximum
maximum: $(TESTS)
	./arrays_test --filter arrays/$@*

.PHONY: clean
clean:
	find . -name '*~' -o -name '*.o' | xargs rm -f
	rm -f $(APPLICATION) $(TESTS)
