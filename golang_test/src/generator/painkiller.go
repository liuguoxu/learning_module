package painkiller

//go:generate stringer -type=Pill

type Pill int

const (
	First Pill = iota
	Seccond
	Third
	Fourth
	Fifth
)
