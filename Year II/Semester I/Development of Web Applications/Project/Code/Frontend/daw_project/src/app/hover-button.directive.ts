import { Directive, ElementRef, HostListener } from '@angular/core';

@Directive({
  selector: '[appHoverButton]'
})
export class HoverButtonDirective {

  constructor(
    public element: ElementRef,
  ) { }

  @HostListener('mouseenter') onMouseEnter() {
    this.highlight('orange');
  }

  @HostListener('mouseleave') onMouseLeave() {
    this.highlight('');
  }

  private highlight(color: string) {
    this.element.nativeElement.style.backgroundColor = color;
  }

}
