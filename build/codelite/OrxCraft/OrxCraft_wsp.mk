.PHONY: clean All

All:
	@echo ----------Building project:[ OrxCraft - Linux Release ]----------
	@"$(MAKE)" -f "OrxCraft.mk" && "$(MAKE)" -f "OrxCraft.mk" PostBuild
clean:
	@echo ----------Cleaning project:[ OrxCraft - Linux Release ]----------
	@"$(MAKE)" -f "OrxCraft.mk" clean
